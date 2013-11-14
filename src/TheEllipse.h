//
//  TheEllipse.h
//  TargetEllip
//
//  Created by Javier Villegas on 3/12/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#ifndef TargetEllip_TheEllipse_h
#define TargetEllip_TheEllipse_h





class TheEllipse {
    
public:
    
    float x;
    float y;
    float a;
    float b;
    float angle;
    float TheGray;
    TheEllipse(float,float,float,float,float,float);
    TheEllipse();
    void set(float,float,float,float,float,float);
    void normalize();
    float getWeigthedLength(float, float, float,float, float,float);
    float getLength();
    friend bool operator>(const TheEllipse& Ell1, const TheEllipse& Ell2);
    friend bool operator<(const TheEllipse& Ell1, const TheEllipse& Ell2);
    friend TheEllipse operator-(const TheEllipse& Ell1, const TheEllipse& Ell2);
    friend TheEllipse operator*(const float& K, const TheEllipse& Ell1);
    
};



#endif






