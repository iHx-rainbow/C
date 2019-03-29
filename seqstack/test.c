#include "seqstack.h"
#include <string.h>
 main()
{
	char str[1000];
	printf("ÇëÊäÈëÄãÒªÅĞ¶ÏµÄ×Ö·û£º");
	scanf("%s",str);	
	int a;
      int f=0;
	int c = strlen(str);
	seqstack *h;
	init(&*h);
	for(a=0;a<c;a++){
		if(str[a]=='('||str[a]=='['||str[a]=='{'){
			push(&*h,str[a]);
		}else if((str[a]==')'&&h->elem[h->top]=='(')||(str[a]==']'&&h->elem[h->top]=='[')||(str[a]=='}'&&h->elem[h->top]=='{')){
			pop(&*h);
			f=1;
		}else{
			f=0;
			break;
		}
		
	} 
	if(f==1){printf("YES");
	}else{printf("NO");
	}	


}
