#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__

class FunzioneBase {

    public:
    
      virtual double Eval(double x) const =0;
      virtual ~FunzioneBase() {;};
    
};

class sign {

    public:

    double eval(double x) const { 
      
      if(x<0) 
        return -1;
      else
        return 1;

    }
};

#endif

    