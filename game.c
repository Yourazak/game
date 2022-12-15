#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

void tab(int value){
    for(int i = 0; i < value; i++){
        printf(" ");
    }
}

struct xorshift32_state {
    uint32_t a;
};

uint32_t xorshift32(struct xorshift32_state *state) {
    uint32_t x = state->a;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return state->a = x;
}

struct xorshift32_state *global_state = NULL;

int last_max = 1;

float rnd(int max) {
    if (global_state == NULL) {
        global_state = malloc(sizeof(struct xorshift32_state));
    }
    if (max == 0) {
        float value = global_state->a / (float)UINT32_MAX;
        return last_max*value;
    }
    last_max = max;
    global_state->a = xorshift32(global_state);
    float value = global_state->a / (float)UINT32_MAX;
    return value*max;
}

int main(){
    tab(26);
    printf ("ICBM\n");
    tab(20);
    printf("CREATIVE COMPUTING\n");
    tab(18);
    printf("MORRISTOWN, NEW JERSEY\n");
    printf("\n\n\n");
    float d = 0;
    int r = 0;
    int T = 0;
    int b = 0;
    float T1 = 0;
    float s = 0;
    float s1 = 0;
    int x1 = 0;
    int y1 = 0;
    int x =  rnd(1) * 800 + 200;
    int y =  rnd(1) * 800 + 200;
    n130:
    s = rnd(1) * 20 + 50;
    s1 = rnd(1) * 20 + 50;
    printf ("-------MISSILE-----         ");
    printf ("--------SAM--------         ------\n");
    printf ("MILES         ");
    printf("MILES         ");
    printf("MILES         ");
    printf("MILES         ");
    printf("HEADING\n");
    printf ("NORTH         ");
    printf("EAST          ");
    printf("NORTH         ");
    printf("EAST          ");
    printf("?\n");
    printf ("----------------------------------");
    printf ("---------------------------\n");
    for(int n = 1; n <= 50; n++){
        printf("%i           ", y);
        printf("%i           ", x);
        printf("%i             ", y1);
        printf("%i             ", x1);
        printf("? ");
        if (x == 0 ) {
            goto n550;
        }
        scanf("%f",&T1);
        T1=T1/57.296;
        int H = rnd(1) * 200 + 1;
        if (H > 0) {
            goto n290;
        }
        if ( H >= 1 && H < 2){
            goto n470;
        } else if (H >= 2 && H < 3){
            goto n490;
        } else if (H >= 3 && H < 4){
            goto n510;
        } else if (H >= 4 && H < 5){
            goto n530;
        }
    n290:
        x1 = (int)(x1+s1*sin(T1));
        y1 = (int)(y1+s1*cos(T1));
        if(pow(x*x+y*y, 2) >s) {
            goto n350;
        }
        x = 0 ;
        y = 0;
        goto n430;
    n350:
        
        b=sqrt(x*x + y*y)/1000;
        T = atan((float)y/(float)x);
        x = (int)(x-s*cos(T)+ rnd(1)*20+r);
        y = (int)(y-s*sin(T)+ rnd(1)*20+r);
        d = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1) );
        
        if (d <= 5 ) {
            goto n440;
        }
        d = (int)(d);
        printf("ICBM & SAM NOW %i ",(int)d);
        printf("MILES APART\n");
    n430:
        continue;
    }
    n440:
        printf("CONGRATULATIONS!  YOUR SAM CAME WITHIN %i ",d);
        printf("MILES OF\n");
    printf ("THE ICBM AND DESTROYED IT!");
        goto n560;
    n470:
    printf("TOO BAD.  YOUR SAM FELL TO THE GROUND!");
        goto n560;
    n490:
    printf("YOUR SAM EXPLODED IN MIDAIR!");
        goto n560;
    n510:
    printf("GOOD LUCK-THE ICBM EXPLODED HARMLESSLY IN MIDAIR!");
        goto n560;
    n530:
    printf("GOOD LUCK-THE ICBM TURNED OUT TO BE A FRIENDLY AIRCRAFT!");
        goto n560;
    n550:
    printf("TOO BAD!");
    printf("THE ICBM JUST HIT YOUR LOCATION!!");
    n560:
    printf("DO YOU WANT TO PLAY MORE? (Y OR N)");
    char a[5];
    scanf("%s",&a);
    if (!strcmp (a, "Y")) goto n130;
}
