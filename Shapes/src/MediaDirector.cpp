#include "MediaDirector.h"

void MediaDirector::setMediaBuilder(stack<MediaBuilder *> *mbs){
    mb=mbs;
}

void MediaDirector::concrete(string content){

    while(content.find("combo")!=string::npos){
        content.replace(content.find("combo"),5,"m");
    }

    stringstream ss;
    ss<<content;
    char c;

    while((c=ss.get())){
        if(ss.eof()){
            break;
        }
        else if(!ss.good()){
            throw std::string("input error!!");
        }
        else if(c=='m' && ss.get()=='('){
            mb->push(new ComboMediaBuilder());
            mb->top()->buildComboMedia();
        }
        else if(c=='r' && ss.get()=='('){
            double arg[4]={0};
            for(int i=0;i<4;i++)
                ss>>arg[i];
            ss.get();

            Rectangle* rec=new Rectangle(arg[0],arg[1],arg[2],arg[3]);
            if(!rec->islegal()){
                throw std::string("input error!!");
            }
            ShapeMediaBuilder* smb=new ShapeMediaBuilder();
            smb->buildShapeMedia(rec);

            if(mb->size()==0){
                mb->push(smb);
            }
            else{
                mb->top()->buildAddShapeMedia((ShapeMedia*)smb->getMedia());
            }
        }
        else if(c=='c' && ss.get()=='('){
            double arg[3]={0};
            for(int i=0;i<3;i++)
                ss>>arg[i];
            ss.get();

            Circle* cir=new Circle(arg[0],arg[1],arg[2]);
            if(!cir->islegal()){
                throw std::string("input error!!");
            }
            ShapeMediaBuilder* smb=new ShapeMediaBuilder();
            smb->buildShapeMedia(cir);

            if(mb->size()==0){
                mb->push(smb);
            }
            else{
                mb->top()->buildAddShapeMedia((ShapeMedia*)smb->getMedia());
            }
        }
        else if(c=='t' && ss.get()=='('){
            double arg[6]={0};
            for(int i=0;i<6;i++)
                ss>>arg[i];
            ss.get();

            Triangle* tri=new Triangle(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5]);
            if(!tri->islegal()){
                throw std::string("input error!!");
            }
            ShapeMediaBuilder* smb=new ShapeMediaBuilder();
            smb->buildShapeMedia(tri);

            if(mb->size()==0){
                mb->push(smb);
            }
            else{
                mb->top()->buildAddShapeMedia((ShapeMedia*)smb->getMedia());
            }
        }
        else if(c==')'){
            if(mb->size()>1){
                ComboMedia* cm=(ComboMedia*)mb->top()->getMedia();
                mb->pop();
                mb->top()->buildAddComboMedia(cm);
            }
        }

    }

    if(mb->size()==0){
        throw std::string("input error!!");
    }

}
