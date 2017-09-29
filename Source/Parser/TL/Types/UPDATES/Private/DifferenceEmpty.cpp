#include "../Public/DifferenceEmpty.h"


//begin namespace block
namespace UPDATES
{

DifferenceEmpty::DifferenceEmpty()
{
	this->_ConstructorID = 1567990072;
}

DifferenceEmpty::DifferenceEmpty(FDateTime date, int32 seq)
{
	this->_ConstructorID = 1567990072;
	this->date = date;
	this->seq = seq;
}
void DifferenceEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->seq);
}


void DifferenceEmpty::OnResponce(BinaryReader& Reader)
{
	date = Reader.TGReadDate();
	seq = Reader.ReadInt();
	this->_Responded = true;
}
DifferenceEmpty::~DifferenceEmpty()
{

}
}//end namespace block
