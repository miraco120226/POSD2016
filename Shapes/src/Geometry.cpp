#include "Geometry.h"

bool Geometry::run()
{
    cout<<":- ";
    string input;
    getline(cin,input);

    stringstream ss;
    ss<<input;

    string temp;
    ss>>temp;

    if(temp==string("def")){
        string name;
        ss>>name;

        if(ss.get()!=' ' || ss.get()!='=' || ss.get()!=' '){
            throw string("input error!");
        }

        string oldContent,content;
        ss>>oldContent;
        content=string(oldContent);

        if(mediaMap.count(name)!=0){
            throw string("the name is already existed");
        }

        while(content.find("Circle")!=string::npos){
            content.replace(content.find("Circle"),6,"c");
        }
        while(content.find("Rectangle")!=string::npos){
            content.replace(content.find("Rectangle"),9,"r");
        }
        while(content.find("Triangle")!=string::npos){
            content.replace(content.find("Triangle"),8,"t");
        }
        while(content.find(",")!=string::npos){
            content.replace(content.find(","),1," ");
        }

        if((content.substr(0,2)==string("c(") || content.substr(0,2)==string("r(") || content.substr(0,2)==string("t(")) && content.substr(content.length()-1,1)==string(")")){
            MediaDirector mdir;
            stack<MediaBuilder *> mb;
            mdir.setMediaBuilder(&mb);
            try{
                mdir.concrete(content);
            }
            catch(string s){
                cout<<s<<endl;
            }

            mediaMap[name]=mb.top()->getMedia();
        }
        else if(content.substr(0,6)==string("combo{") && content.substr(content.length()-1,1)==string("}")){
            ComboMediaBuilder cmb;
            cmb.buildComboMedia();
            content=content.substr(6,content.length()-7);
            stringstream ss;
            ss<<content;
            string mediaName;
            while(!ss.eof()){
                ss>>mediaName;
                if(mediaMap.count(mediaName)!=0){
                    cmb.buildAddMedia(mediaMap[mediaName]);
                }
                else{
                    throw std::string("the name of media is not existed");
                }
            }
            mediaMap[name]=cmb.getMedia();
        }
        else{
            throw string("input error!");
        }
        cout<<">> "<<oldContent;
    }
    else if(temp==string("delete")){
        string shape;
        ss>>shape;
        if(mediaMap.count(shape)==0){
            throw string("the name of media is not existed");
        }

        if(ss.eof()){
            ComboMedia* cmm;
            for (auto &i : mediaMap) {
                cmm=dynamic_cast<ComboMedia *>(i.second);
                if(cmm!=0){
                    i.second->removeMediaByRef(mediaMap[shape]);
                }
            }
            mediaMap.erase(shape);
        }
        else{
            string stringFrom;
            string comboMedia;
            ss>>stringFrom;
            ss>>comboMedia;
            if(stringFrom!=string("from") || mediaMap.count(comboMedia)==0){
                throw string("input error!");
            }
            if(!mediaMap[comboMedia]->removeMediaByRef(mediaMap[shape])){
                throw string("the name of media is not existed in the comboMedia");
            }
        }
        cout<<">> delete successful";
    }
    else if(temp==string("show")){
        string ouput("");
        for(auto imap: mediaMap)
            ouput=ouput+imap.first+'\n';
        cout<<ouput.substr(0,ouput.length()-1);
    }
    else if(temp==string("add")){
        string comboMedia1;
        string stringTo;
        string comboMedia2;
        ss>>comboMedia1;
        ss>>stringTo;
        ss>>comboMedia2;
        if(stringTo!=string("to") || mediaMap.count(comboMedia1)==0 || mediaMap.count(comboMedia2)==0){
            throw string("input error!");
        }

        mediaMap[comboMedia2]->add(mediaMap[comboMedia1]);
        GeometryVisitor gv(&mediaMap);
        mediaMap[comboMedia2]->accept(&gv);
        DescriptionVisitor dv;
        mediaMap[comboMedia2]->accept(&dv);
        cout<<">>"<<comboMedia2<<" = "<<gv.getDescription()<<"= "<<dv.getDescription();
    }
    else if(temp==string("save")){
        string name;
        string stringTo;
        string fileName;
        ss>>name;
        ss>>stringTo;
        ss>>fileName;
        fileName=fileName.substr(1,fileName.length()-2);
        if(stringTo!=string("to") || mediaMap.count(name)==0 || fileName.length()==0){
            throw string("input error!");
        }

        GeometryVisitor gv(&mediaMap);
        mediaMap[name]->accept(&gv);
        DescriptionVisitor dv;
        mediaMap[name]->accept(&dv);

        ofstream os;
        os.open(fileName,ios::out);
        if(!os){
            throw string("fail to open file");
        }
        os<<dv.getDescription()<<endl<<gv.getDescription();
        os.close();

        cout<<">>"<<name<<" saved to "<<fileName;
    }
    else if(temp==string("load")){
        string fileName;
        ss>>fileName;
        fileName=fileName.substr(1,fileName.length()-2);

        MediaDirector mdir;
        stack<MediaBuilder *> mb;
        mdir.setMediaBuilder(&mb);

        if(access(fileName.c_str(),R_OK)!=0){
            throw string("open file error!");
        }
        ifstream is;
        is.open(fileName,ios::in);
        string str1,str2;
        getline(is,str1);
        getline(is,str2);
        is.close();
        //mdir.concrete(str1);
        while(str2.find("{")!=string::npos){
            str2.replace(str2.find("{"),1," ");
        }
        while(str2.find("}")!=string::npos){
            str2.replace(str2.find("}"),1," ");
        }

        GeometryDirector gd;
        gd.concrete(str1,str2);

        /*FillMapVisitor fmv(str2);
        mb.top()->getMedia()->accept(&fmv);
*/
        map<string, Media*> mediaMap2=mediaMap;
        for (auto &i : gd.getMap()) {
            if(mediaMap.count(i.first)!=0){
                mediaMap=mediaMap2;
                throw string("merge failed,the name of media is already existed");
            }
            mediaMap[i.first]=i.second;
        }

        stringstream ss;
        ss<<str2;
        string comboName;
        ss>>comboName;

        GeometryVisitor gv(&mediaMap);
        mediaMap[comboName]->accept(&gv);
        DescriptionVisitor dv;
        mediaMap[comboName]->accept(&dv);
        cout<<">> loading "<<fileName<<" ..."<<endl;
        cout<<comboName<<" = "<<gv.getDescription()<<"= "<<dv.getDescription();
    }
    else if(temp.length()>6 && temp.substr(temp.length()-6,6)==string(".area?")){
        string name=temp.substr(0,temp.length()-6);
        if(mediaMap.count(name)==0){
            throw string("the name is not existed");
        }

        AreaVisitor av;
        mediaMap[name]->accept(&av);
        cout<<">>"<<av.getArea();
    }
    else if(temp.length()>11 && temp.substr(temp.length()-11,11)==string(".perimeter?")){
        string name=temp.substr(0,temp.length()-11);
        if(mediaMap.count(name)==0){
            throw string("the name is not existed");
        }

        PerimeterVisitor pv;
        mediaMap[name]->accept(&pv);
        cout<<">>"<<pv.getPerimeter();
    }
    else if(temp==string("clear")){
        mediaMap.clear();
        cout<<">> clear successful";
    }
    else if(temp==string("quit")){
        return false;
    }
    else{
        throw string("input error!");
    }

    cout<<endl<<endl;
    return true;
}
