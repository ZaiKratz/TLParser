#include "../Public/SentCodeTypeCall.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeCall::SentCodeTypeCall()
{
	this->_ConstructorID = -1478143149;
}

SentCodeTypeCall::SentCodeTypeCall(int32 length)
{
	this->_ConstructorID = -1478143149;
	this->length = length;
}
void SentCodeTypeCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->length);
}


void SentCodeTypeCall::OnResponce(BinaryReader& Reader)
{
	length = Reader.ReadInt();
}
SentCodeTypeCall::~SentCodeTypeCall()
{

}
}//end namespace block
