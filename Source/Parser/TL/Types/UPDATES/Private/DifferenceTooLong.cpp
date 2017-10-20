#include "../Public/DifferenceTooLong.h"


//begin namespace block
namespace UPDATES
{

DifferenceTooLong::DifferenceTooLong()
{
	this->_ConstructorID = 1258196845;
}

DifferenceTooLong::DifferenceTooLong(int32 pts)
{
	this->_ConstructorID = 1258196845;
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
	this->_Responded = true;
}
DifferenceTooLong::~DifferenceTooLong()
{
}
}//end namespace block
