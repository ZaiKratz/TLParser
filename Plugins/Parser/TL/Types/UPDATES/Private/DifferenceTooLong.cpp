#include "../Public/DifferenceTooLong.h"


//begin namespace block
namespace UPDATES
{

DifferenceTooLong::DifferenceTooLong()
{
	this->_ConstructorID = 1838153290;
}

DifferenceTooLong::DifferenceTooLong(int32 pts)
{
	this->_ConstructorID = 1838153290;
	this->pts = pts;
}
void DifferenceTooLong::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->pts);
}


void DifferenceTooLong::OnResponce(BinaryReader& Reader)
{
	pts = Reader.ReadInt();
}
DifferenceTooLong::~DifferenceTooLong()
{

}
}//end namespace block
