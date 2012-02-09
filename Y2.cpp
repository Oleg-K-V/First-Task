#include <iostream>
#include <bitset>

using namespace std;
//6
unsigned long int clear_all(unsigned long int i)
{
	unsigned long int zm=i;
	i|=i<<1;
	i|=i<<2;
	i|=i<<4;
	i|=i<<8;
	i|=i<<16;
	i|=i<<32;//� ��������� ���� ���������� ������ �� ����� ��������� ���� 1 �� ��������� ���
	i^=i<<1;//������ �� �������� �� ��� ��� ������ ���������
	return i;
}
//7
unsigned long int obm_bit(unsigned long int i)
{
	unsigned long int x1,x2,res;
	x1=(i&0x55555555);//������ ������ ��������� ��
	x2=((i>>1)&0x55555555);//������ �� 1 ��� � ����� � ������ ������ ��������� ��
	res=((x1<<1)|(x2));//������ ����������
	return res;
}
//8
unsigned long int bit_set_h(unsigned long int i)
{
	unsigned long int zm=i;
	i&=((i>>1)|0x80000000);
	i&=((i>>2)|0xC0000000);
	i&=((i>>4)|0xF0000000);
	i&=((i>>8)|0xFF000000);
	i&=((i>>16)|0xFFFF0000);
	i&=((i>>32)|0XFFFFFFFF);//� ��������� ���� ���������� ������ �� ����� ��������� ���� 0 ���� �������� ���
	i^=((i>>1)^0x80000000);//������ �� �������� �� ��� ��� ������ ��������
	return i|=zm;//����������� ����� ������� ��
}
//9
unsigned long int bit_set(unsigned long int i)
{
	unsigned long int zm=i;
	i&=((i<<1)|1);
	i&=((i<<2)|3);
	i&=((i<<4)|0xF);
	i&=((i<<8)|0xFF);
	i&=((i<<16)|0xFFFF);
	i&=((i<<32)|0XFFFFFFFF);//� ��������� ���� ���������� ������ �� ����� ��������� ���� 0 ����������� ���
	i^=((i<<1)|1);//������ �� �������� �� ��� ��� ������ ���������
	return i|=zm;//����������� ����� �������� ��
}
//10
unsigned long int bitclear(unsigned long int i)
{
	unsigned long int zm=i;
	i|=i>>1;
	i|=i>>2;
	i|=i>>4;
	i|=i>>8;
	i|=i>>16;
	i|=i>>32;//� ��������� ���� ���������� ������ �� ����� ��������� ���� 1 ���� �������� ���
	i^=i>>1;//������ �� �������� �� ��� ��� ������ ��������
	i=~i;//��������� ���������
	return i&=zm;//������ ����� ������� ��
}
//11
int Per1bit(unsigned long int i,int j)
{
	if (i&0x00000001)//��������� �� ����� �� 0
		return 1+j;//��������� ����� 0
	else return 2+j;//��������� ����� 1
}
int Per2bit(unsigned long int i,int j)
{
	if (i&0x00000003)//��������� �� � ������ 2 �� ���������� ��
		return Per1bit(i,j);//�������� ������� ������� �������� 2-�� �� � ����� �� � ����� ���� ����� �� �������
	else
	{	
		unsigned long int zm=i>>2;//������ ����� �� 2 �� 
		return Per1bit(zm,j+2);;//�������� ������� ������� �������� 2-�� �� � ����� �� �� ����� ���� ����� ��������� �� 2
	}
}
int Per4bit(unsigned long int i,int j)
{
	if (i&0x0000000F)//��������� �� � ������ 4 �� ���������� ��
		return Per2bit(i,j);//�������� ������� ������� �������� 4-�� �� � ����� �� � ����� ���� ����� �� �������
	else
	{
		unsigned long int zm=i>>4;//������ ����� �� 4 �� 
		return Per2bit(zm,j+4);;//�������� ������� ������� �������� 4-�� �� � ����� �� �� ����� ���� ����� ��������� �� 4
	}
}
int Per8bit(unsigned long int i,int j)
{
	if (i&0x000000FF)//��������� �� � ������ 8 �� ���������� ��
		return Per4bit(i,j);//�������� ������� ������� �������� 8-�� �� � ����� �� � ����� ���� ����� �� �������
	else
	{
		unsigned long int zm=i>>8;//������ ����� �� 8 �� 
		return Per4bit(zm,j+8);//�������� ������� ������� �������� 8-�� �� � ����� �� �� ����� ���� ����� ��������� �� 8
	}
}
int Per16bit(unsigned long int i)
{
	if (i&0x0000FFFF)//��������� �� � ������ 16 �� ���������� ��
		return Per8bit(i,0);//�������� ������� ������� �������� 16-�� �� � ����� �� � ����� ���� ����� �� ������� ����� ����� 0
	else if ((i>>16)&0x0000FFFF)//��������� �� � ������ 16 �� ���������� ��
	{
		unsigned long int zm=i>>16;//������ ������� �� �� 16
		return Per8bit(zm,16);//�������� ������� ������� �������� 16-�� �� � ����� �� �� ����� ���� ����� ��������� �� 16
	}
	else return -1;
}
//12
unsigned long int parbit(unsigned long int zm)
{
	unsigned long int x1,x2,res;
	x1=(zm&0x33333333);//������ ����� ���� ��
	x2=((zm>>2)&0x33333333);//������ �� 2 ��� � ����� � ������ ����� ���� ��
	res=((x1<<2)|(x2));//������ ����������
	return res;
}
//13
int Summa(unsigned long int i)
{
	return (i&1)+(i>>1);//������ ��� �������� ���
}
int dil2(unsigned long int i)
{
	return Summa(i&0x00000003)+Summa(i>>2);//������ 4 �������� ���
}
int dil4(unsigned long int i)
{
	return dil2(i&0x0000000F)+dil2(i>>4);//������ 8 �������� ���
}
int dil8(unsigned long int i)
{
	return dil4(i&0x000000FF)+dil4(i>>8);//������ 16 �������� ���
}
int dil16(unsigned long int i)
{
	return dil8(i&0x0000FFFF)+dil8(i>>16);//������ ��� �����
}
//14
int Klog(unsigned long int i)
{
		unsigned long int zm=i;
	i|=i>>1;
	i|=i>>2;
	i|=i>>4;
	i|=i>>8;
	i|=i>>16;
	i|=i>>32;//� ��������� ���� ���������� ������ �� ����� � ��������� ���� 1 ���� �������� ���
	i^=i>>1;//������ �� �������� �� ��� ��� ������ ��������
	int j=0;
	for (;i!=0;i=i>>1)//����� ������� �� ������ � ��������� �� �� �� ������� 0
	{
		j++;
	}
	return j;
}
int main()
{
	unsigned long int i=0;
	bitset<32> chuslo,res;
	cout<<"Wedit budlaska chuslo"<<endl;
	while(cin>>i&&i!=0)
	{
		chuslo=long int(i);
		cout<<"10 zavdnja"<<endl;
		//10
		res=long int(bitclear(i));
		cout<<"Rezyltatom poshuky i ochushchena samogo starshogo vstanovlenogo chusla taki"<<endl
			<<chuslo<<" - pochatkoe znachena"<<endl
			<<res<<" - rezyltat"<<endl<<"11 zavdnja"<<endl;
		//11
		cout<<"Rezyltatom poshuky samigo molodshogo vstanovlenogo bita v chusli"<<endl
			<<chuslo<<"\tje nastupne chuslo ("
			<<Per16bit(i)<<")"<<endl<<"12 zavdnja"<<endl;
		//12
		res=long int(parbit(i));
		cout<<"Rezyltatom obminy par bitiv mischamu, bydyt nastypnumu"<<endl
			<<chuslo<<" - pochatkove znachena"<<endl
			<<res<<" - rezultat"<<endl<<"13 zavdnja"<<endl;
		//13
		cout<<"Rezyltatom summuvanja vsih bit chusla x"<<endl
			<<chuslo<<"\tbyde nastupnum ("
			<<dil16(i)<<")"<<endl<<"14 zavdnja"<<endl;
		//14
		cout<<"Rezyltatom znahodgjenja logarufma k=[log2(x)], chusla "<<endl
			<<chuslo<<endl
			<<"bude nomer stepeni dviiku zaykryglenoi do nuchogo znachenja ("
			<<Klog(i)<<")"<<endl<<endl//�������� ������� ����������� ��������� log2(i)
			<<"--------------------------------------------------------------------------------"
			<<"Wedit budlaska chuslo"<<endl;
	}
	return 0;
}