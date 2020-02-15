struct Pos // 位置，
{
	double x;
	double y;
};
class Grass {
public:
	Grass();
	static int getCnt() //获取草当前总数量
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
	static int cnt; //草总数量
	Pos pos; //位置
	int hp; //血条（距离死亡的时间等,待定义）
};
int Grass::cnt = 0;
Grass::Grass()
{
	/*
	随机位置产生草
	基本参数
	对象添加进入列表或其他
	界面上添加图片
	*/
}
Grass::~Grass() {
	/*
	被吃了或正常死亡
	清除图片
	移出列表等
	*/
}

class Animal {
public:
	Pos getPos()
	{
		return pos;
	}
	Pos FindPrey(/*猎物列表*/); //寻找猎物
	void RandomMove(); //未发现猎物前随机移动
	void Move();//移动及显示
protected:
	Pos pos; //位置
	int hp; //血条（距离死亡的时间等,待定义）
	int degree; //饥饿值
	double speed; //速度；
};

class Wolf :public Animal
{
public:
	Wolf();//类似Grass类构造函数
	~Wolf();
	void Catch();//抓捕猎物
	void Clock(); //时间
};
class Sheep :public Animal
{
public:
	Sheep();
	~Sheep();
	void Escape();
	void Clock();
};