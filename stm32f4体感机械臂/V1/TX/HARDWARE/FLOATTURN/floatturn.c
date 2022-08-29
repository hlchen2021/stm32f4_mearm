#include "floatturn.h"
#define EPISON 1e-7                             //float����ֱ����0�Ƚϴ�С

void floatturn1(float *a, unsigned char *p, float *z)	    //a[]��������pitch roll yaw �Ƕ�ֵ��p[]���ڴ洢pitch yaw roll����,��p[1]��ʼ�����������˻�Ϊָ��
{
    int b[3];                                   //b[]�����洢 pitch roll yaw ת���ɷǸ���������
    int s;				                        			//���ڴ洢b[i]������
		int i,j;


    for(i=0; i<3; i++)
    {
        b[i] = a[i]*10+900;
				if(b[i]<0)
					b[i]=0;
				if(b[i]>1800)
					b[i]=180;
    }

    for(i=0; i<3; i++)
    {
        for(j=4*i+1; j<=4*i+4; j++)
        {
            s = b[i]%10;
            p[j] = s;		//�洢ÿһλ,�ɵ�λ���λ
            b[i] = b[i]/10;
        }
    }
		
		z[0]=p[1]*0.1+p[2]+p[3]*10+p[4]*100;
		z[1]=p[5]*0.1+p[6]+p[7]*10+p[8]*100;
		z[2]=p[9]*0.1+p[10]+p[11]*10+p[12]*100;
}

void floatturn2(float *a, unsigned char *p, float *z)
{
	  int b[3];                                   //b[]�����洢 pitch roll yaw ת���ɷǸ���������
    int s;				                        			//���ڴ洢b[i]������
		int i,j;
	
	    for(i=0; i<3; i++)
    {
        b[i] = a[i]*10;
        if(b[i] < 0)
            b[i] = -b[i];
    }

    for(i=0; i<3; i++)
    {
        for(j=4*i+1; j<=4*i+4; j++)
        {
            s = b[i]%10;
            p[j] = s;		//�洢ÿһλ,�ɵ�λ���λ
            b[i] = b[i]/10;
        }
    }
		
		z[0]=p[1]*0.1+p[2]+p[3]*10+p[4]*100;
		z[1]=p[5]*0.1+p[6]+p[7]*10+p[8]*100;
		z[2]=p[9]*0.1+p[10]+p[11]*10+p[12]*100;
}
