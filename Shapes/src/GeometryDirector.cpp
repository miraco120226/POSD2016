#include "GeometryDirector.h"

void GeometryDirector::concrete(string line1,string line2){

    stack<MediaBuilder*> mbs;
    stack<string> ns;

    while(line1.find("combo")!=string::npos){
        line1.replace(line1.find("combo"),5,"m");
    }

    stringstream ss1;
    ss1<<line1;
    stringstream ss2;
    ss2<<line2;
    string name;
    char c;

    while((c=ss1.get())){
        if(ss1.eof()){
            break;
        }
        else if(!ss1.good()){
            throw std::string("input error!!");
        }
        else if(c=='m' && ss1.get()=='('){
            mbs.push(new ComboMediaBuilder());
            mbs.top()->buildComboMedia();
            ss2>>name;
            ns.push(name);
        }
        else if(c=='r' && ss1.get()=='('){
            double arg[4]={0};
            for(int i=0;i<4;i++)
                ss1>>arg[i];
            ss1.get();

            Rectangle* rec=new Rectangle(arg[0],arg[1],arg[2],arg[3]);
            if(!rec->islegal()){
                throw std::string("input wrong rectangle");
            }

            ShapeMediaBuilder* smb=new ShapeMediaBuilder();
            smb->buildShapeMedia(rec);

            ss2>>name;

            if(mbs.size()==0){
                mediaMap[name]=smb->getMedia();
            }
            else{
                if(mediaMap.count(name)!=0){
                    DescriptionVisitor dv;
                    mediaMap[name]->accept(&dv);
                    if(dv.getDescription()==rec->description()){
                        mbs.top()->buildAddShapeMedia((ShapeMedia*)mediaMap[name]);
                    }
                    else{
                        throw string("the name of media is already existed");
                    }

                }
                else{
                    mediaMap[name]=smb->getMedia();
                    mbs.top()->buildAddShapeMedia((ShapeMedia*)mediaMap[name]);
                }
            }
        }
        else if(c=='c' && ss1.get()=='('){
            double arg[3]={0};
            for(int i=0;i<3;i++)
                ss1>>arg[i];
            ss1.get();

            Circle* cir=new Circle(arg[0],arg[1],arg[2]);
            if(!cir->islegal()){
                throw std::string("input wrong circle");
            }
            ShapeMediaBuilder* smb=new ShapeMediaBuilder();
            smb->buildShapeMedia(cir);

            ss2>>name;

            if(mbs.size()==0){
                mediaMap[name]=smb->getMedia();
            }
            else{
                if(mediaMap.count(name)!=0){
                    DescriptionVisitor dv;
                    mediaMap[name]->accept(&dv);
                    if(dv.getDescription()==cir->description()){
                        mbs.top()->buildAddShapeMedia((ShapeMedia*)mediaMap[name]);
                    }
                    else{
                        throw string("the name of media is already existed");
                    }

                }
                else{
                    mediaMap[name]=smb->getMedia();
                    mbs.top()->buildAddShapeMedia((ShapeMedia*)mediaMap[name]);
                }
            }
        }
        else if(c=='t' && ss1.get()=='('){
            double arg[6]={0};
            for(int i=0;i<6;i++)
                ss1>>arg[i];
            ss1.get();

            Triangle* tri=new Triangle(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5]);
            if(!tri->islegal()){
                throw std::string("input wrong triangle");
            }
            ShapeMediaBuilder* smb=new ShapeMediaBuilder();
            smb->buildShapeMedia(tri);

            ss2>>name;

            if(mbs.size()==0){
                mediaMap[name]=smb->getMedia();
            }
            else{
                if(mediaMap.count(name)!=0){
                    DescriptionVisitor dv;
                    mediaMap[name]->accept(&dv);
                    if(dv.getDescription()==tri->description()){
                        mbs.top()->buildAddShapeMedia((ShapeMedia*)mediaMap[name]);
                    }
                    else{
                        throw string("the name of media is already existed");
                    }
                }
                else{
                    mediaMap[name]=smb->getMedia();
                    mbs.top()->buildAddShapeMedia((ShapeMedia*)mediaMap[name]);
                }
            }
        }
        else if(c==')'){
            if(mbs.size()>=1){
                ComboMedia* cm=(ComboMedia*)mbs.top()->getMedia();
                if(mediaMap.count(ns.top())!=0){
                    DescriptionVisitor dv1;
                    mediaMap[ns.top()]->accept(&dv1);
                    DescriptionVisitor dv2;
                    cm->accept(&dv2);
                    if(dv1.getDescription()==dv2.getDescription() && mbs.size()>1){
                        mbs.pop();
                        mbs.top()->buildAddComboMedia((ComboMedia*)mediaMap[ns.top()]);
                        ns.pop();
                    }
                    else{
                        throw string("the name of comboMedia is already existed");
                    }
                }
                else{
                    mediaMap[ns.top()]=cm;
                    if(mbs.size()>1){
                        mbs.pop();
                        mbs.top()->buildAddComboMedia(cm);
                        ns.pop();
                    }
                }
            }
        }
    }
}

map<string, Media*> GeometryDirector::getMap(){
    return mediaMap;
}
