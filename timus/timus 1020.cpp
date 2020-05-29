    #include<stdio.h>
    #include<math.h>

    typedef struct
    {
        double x;
        double y;
        double l;
        double w;
    }cord;

    #define pi 3.14159

    double dis(cord a,cord b)
    {
        double temp;
        temp=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
        return sqrt(temp);
    }

    int main()
    {
        cord point[101],p1,p2,p;
        int i,n;
        double temp,l1,l2,l,angle,radius;
        scanf("%d %lf",&n,&radius);
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&point[i].x,&point[i].y);
        }

        for(i=0;i<n-1;i++)
        {
            p=point[i];
            if(i==0)
            {
                p1=point[n-1];
                p2=point[i+1];
                point[n-1].l=dis(p,p1);
                point[i].l=dis(p,p2);
            }
            else
            {
                p2=point[i+1];
                point[i].l=dis(p,p2);

            }
        }
        double sum=0;
        for(i=0;i<n;i++)
        {
            sum+=point[i].l;

        }
        sum+=(2*pi*radius);
        printf("%.2lf\n",sum);
        return 0;
    }
