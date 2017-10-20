#include "../Public/InputBotInlineMessageID.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageID::InputBotInlineMessageID()
{
	this->_ConstructorID = -1995686519;
}

InputBotInlineMessageID::InputBotInlineMessageID(int32 dc_id, unsigned long long id, unsigned long long access_hash)
{
	this->_ConstructorID = -1995686519;
	this->dc_id = dc_id;
	this->id = id;
	this->access_hash = access_hash;
}
void InputBotInlineMessageID::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->dc_id);
	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
}


void InputBotInlineMessageID::OnResponce(BinaryReader& Reader)
{
	dc_id = Reader.ReadInt();
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	this->_Responded = true;
}
InputBotInlineMessageID::~InputBotInlineMessageID()
{
}
}//end namespace block
