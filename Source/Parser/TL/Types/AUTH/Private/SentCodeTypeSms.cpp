#include "../Public/SentCodeTypeSms.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeSms::SentCodeTypeSms()
{
	this->_ConstructorID = -1073693790;
}

SentCodeTypeSms::SentCodeTypeSms(int32 length)
{
	this->_ConstructorID = -1073693790;
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
	this->_Responded = true;
}
SentCodeTypeSms::~SentCodeTypeSms()
{

}
}//end namespace block
