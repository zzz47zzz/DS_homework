struct Pos // λ�ã�
{
	double x;
	double y;
};
class Grass {
public:
	Grass();
	static int getCnt() //��ȡ�ݵ�ǰ������
	{
		return cnt;
	}
	Pos getPos()
	{
		return pos;
	}
	void Clock();
	~Grass();
private:
	static int cnt; //��������
	Pos pos; //λ��
	int hp; //Ѫ��������������ʱ���,�����壩
};
int Grass::cnt = 0;
Grass::Grass()
{
	/*
	���λ�ò�����
	��������
	������ӽ����б������
	���������ͼƬ
	*/
}
Grass::~Grass() {
	/*
	�����˻���������
	���ͼƬ
	�Ƴ��б��
	*/
}

class Animal {
public:
	Pos getPos()
	{
		return pos;
	}
	Pos FindPrey(/*�����б�*/); //Ѱ������
	void RandomMove(); //δ��������ǰ����ƶ�
	void Move();//�ƶ�����ʾ
protected:
	Pos pos; //λ��
	int hp; //Ѫ��������������ʱ���,�����壩
	int degree; //����ֵ
	double speed; //�ٶȣ�
};

class Wolf :public Animal
{
public:
	Wolf();//����Grass�๹�캯��
	~Wolf();
	void Catch();//ץ������
	void Clock(); //ʱ��
};
class Sheep :public Animal
{
public:
	Sheep();
	~Sheep();
	void Escape();
	void Clock();
};