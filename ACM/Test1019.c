#include <stdio.h>

typedef struct
{
    //int bianhao;
    float x;
    float y;
    float z;
} Planet;

void main()
{

    /*int num;
    scanf("%d", &num);*/

    Planet p0, p1, p2, p3, p4, p5, p6;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //p[i].zuobiao[j]
            //printf("%d",i);
        }
    }

    p0.x=1062.961900;
    p0.y=47382.348900;
    p0.z=49636.324000;
    p1.x=21829.052500;
    p1.y=75418.119200;
    p1.z=6862.009300;
    p2.x=24339.931000;
    p2.y=6028.722000;
    p2.z=27365.733500;
    p3.x=20111.459200;
    p3.y=22797.250400;
    p3.z=42073.367900;
    p4.x=29601.644400;
    p4.y=39841.340000;
    p4.z=55461.667800;
    p5.x=21829.052500;
    p5.y=75418.119200;
    p5.z=6862.009300;
    p6.x=20111.459200;
    p6.y=22797.250400;
    p6.z=42073.367900;

    Planet zhong;
    zhong.x=(p5.x+p6.x);

    printf("%.3f",zhong.x);
}
