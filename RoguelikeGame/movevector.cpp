#include "movevector.h"

MoveVector::MoveVector()
{
    for(int i=0;i<4;i++)
    {
        this->StateofMoveKeys[i]=QString("unpressed");
    }
    this->toZeroVector();
}

void MoveVector::toZeroVector()//归零向量
{
    this->Vx=0;
    this->Vy=0;
}

void MoveVector::GenerateVector()//根据按键状态生成单位向量
{
    this->toZeroVector();
    if(this->StateofMoveKeys[0]==QString("pressed"))//左
    {
        this->AddVx(-0.5);
    }
    if(this->StateofMoveKeys[1]==QString("pressed"))//上
    {
        this->AddVy(-0.5);
    }
    if(this->StateofMoveKeys[2]==QString("pressed"))//下
    {
        this->AddVy(0.5);
    }
    if(this->StateofMoveKeys[3]==QString("pressed"))//右
    {
        this->AddVx(0.5);
    }
    qreal length=qSqrt(this->Vx*this->Vx+this->Vy*this->Vy);
    if(length!=qreal(0.0))//向量归一化
    {
        this->Vx=this->Vx/length;
        this->Vy=this->Vy/length;
    }
}

void MoveVector::AddVx(qreal deltax)
{
    this->Vx+=deltax;
}

void MoveVector::AddVy(qreal deltay)
{
    this->Vy+=deltay;
}
