#include "../Public/InputMessageEntityMentionName.h"


//begin namespace block
namespace COMMON
{

InputMessageEntityMentionName::InputMessageEntityMentionName()
{
	this->_ConstructorID = 546203849;
}

InputMessageEntityMentionName::InputMessageEntityMentionName(int32 offset, int32 length, COMMON::InputUser*  user_id)
{
	this->_ConstructorID = 546203849;
	this->offset = offset;
	this->length = length;
	this->user_id = user_id;
}
void InputMessageEntityMentionName::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
	this->user_id->OnSend(Writer);
}


void InputMessageEntityMentionName::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
	user_id = reinterpret_cast<COMMON::InputUser* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputMessageEntityMentionName::~InputMessageEntityMentionName()
{

}
}//end namespace block
