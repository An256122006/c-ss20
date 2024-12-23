#include <stdio.h>
#include <string.h>
typedef struct Sach{
	char namebook[50];
	int price;
	char author[50];
}sach;
void print(sach *std,int *length)
{
	for (int i=0; i<*length; i++)
	{
		printf ("sach thu %d:\n",i+1);
		printf ("id:%d\n",i+1);
		printf ("ten sach sach:%s\n",std[i].namebook);
		printf ("gia tien:%d\n",std[i].price);
		printf ("tac gia:%s\n",std[i].author);
	}
}
void update(sach *std,int *length)
{
	int addindex;
	printf ("moi ban nhap vi tri muon them:");
	scanf ("%d",&addindex);
	addindex--;
	if (addindex>=0 && addindex<=*length)
	{
		for (int i=*length; i>addindex;i--)
		{
			std[i]=std[i-1];
		}
		fflush(stdin);
		printf ("moi ban nhap ten sach :\n");
		fgets(std[addindex].namebook,50,stdin);
		std[addindex].namebook[strcspn(std[addindex].namebook,"\n")]='\0';
		printf ("moi ban nhap gia tien:");
		scanf ("%d",&std[addindex].price);
		fflush(stdin);
		printf ("moi ban nhap tac gia :\n");
		fgets(std[addindex].author,50,stdin);
		std[addindex].author[strcspn(std[addindex].author,"\n")]='\0';
		(*length)++;
	}else
	{
		printf ("khong hop le\n");
	}
}
void sua(sach *std,int *length)
{
	int addindex;
	printf ("moi ban nhap ma sach muon sua:");
	scanf ("%d",&addindex);
	addindex--;
	fflush(stdin);
	printf ("moi ban nhap ten sach muon sua :\n");
	fgets(std[addindex].namebook,50,stdin);
	std[addindex].namebook[strcspn(std[addindex].namebook,"\n")]='\0';
	printf ("moi ban nhap gia tien muon sua:");
	scanf ("%d",&std[addindex].price);
	fflush(stdin);
	printf ("moi ban nhap tac gia muon sua :\n");
	fgets(std[addindex].author,50,stdin);
	std[addindex].author[strcspn(std[addindex].author,"\n")]='\0';
}
void xoa(sach *std,int *length)
{
	int addindex;
	printf ("moi ban nhap vi tri muon xoa:");
	scanf ("%d",&addindex);
	addindex--;
	if (addindex>=0 && addindex<=*length)
	{
		for (int i=addindex; i<*length;i++)
		{
			std[i]=std[i+1];
		}
		(*length)--;
	} else
	{
		printf ("khong hop le\n");
	}
}
void tim(sach *std,int *length)
{
	char search[50];
	printf ("moi ban nhap ten sach muon tim:");
	fflush(stdin);
	fgets(search,50,stdin);
	search[strcspn(search,"\n")]='\0';
	int temp=-1;
	for (int i=0; i<*length;i++)
	{
		if (strcmp(std[i].namebook,search)==0)
		{
			temp=i;
			printf ("sach thu %d:\n",temp+1);
	     	printf ("id:%d\n",temp+1);
		    printf ("ten sach:%s\n",std[temp].namebook);
	    	printf ("gia tien:%d\n",std[temp].price);
		    printf ("tac gia:%s\n",std[temp].author);
		}
	}
	if (temp==-1)
	{
		printf ("ko tim thay phan tu\n");
	}
}
void sapxep(sach *std,int *length)
{
	sach temp;
	for (int i=0; i<(*length)-1; i++)
	{
		for (int j=0;j<(*length)-1-i; j++)
		{
			if (std[j].price>std[j+1].price)
			{
			    temp=std[j];
				std[j]=std[j+1];
				std[j+1]=temp;
			}
		}
	}
}	
int main()
{
	int value,length;
	
	sach user[100];
    
	do
	{
		printf ("1.nhap so luong va thong tin sach\n");
		printf ("2.Hi?n th? sách \n");
		printf ("3.Thêm sach\n");
		printf ("4.C?p nh?t thông tin sách theo mã sách\n");
		printf ("5.xoa sach\n");
		printf ("6.S?p x?p sách theo giá\n");
		printf ("7.tim sach\n");
		printf ("8.thoat\n");
		printf ("moi ban nhap lua chon:");
		scanf ("%d",&value);
		switch (value)
		{
			case 1:
				printf("moi ban nhap so phan tu sach:");
	            scanf ("%d",&length);
	            for (int i=0; i<length; i++)
             	{
                	printf ("sach thu %d:\n",i+1);
		            printf ("moi ban nhap ten sach :\n");
		            fflush(stdin);
	            	fgets(user[i].namebook,50,stdin);
	             	user[i].namebook[strcspn(user[i].namebook,"\n")]='\0';
		            printf ("moi ban nhap gia tien:");
		            scanf ("%d",&user[i].price);
		            fflush(stdin);
		            printf ("moi ban nhap tac gia :\n");
		            fgets(user[i].author,50,stdin);
		            user[i].author[strcspn(user[i].author,"\n")]='\0';
               	} 
			case 2:
				print(user,&length);
				break;
			case 3:
				update(user,&length);
				print(user,&length);
				break;
			case 4:
				sua(user,&length);
				print(user,&length);
				break;
			case 5:
				xoa(user,&length);
				print(user,&length);
				break;
			case 6:
				sapxep(user,&length);
				print(user,&length);
				break;
			case 7:
				tim(user,&length);
				break;
			case 8:
				printf ("thoat");
				return 1;
			default:
				printf ("khong hop le\n");
				break;
		}
	}while (1);
}
