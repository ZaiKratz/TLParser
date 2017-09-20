#include "../Public/SentCodeTypeSms.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeSms::SentCodeTypeSms()
{
	this->_ConstructorID = -1564802880;
}

SentCodeTypeSms::SentCodeTypeSms(int32 length)
{
	this->_ConstructorID = -1564802880;
	this->length = length;
}
void SentCodeTypeSms::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->length);
}


void SentCodeTypeSms::OnResponce(BinaryReader& Reader)
{
	length = Reader.ReadInt();
}
SentCodeTypeSms::~SentCodeTypeSms()
{

}
}//end namespace block
