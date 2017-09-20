#include "../Public/InputGameShortName.h"


//begin namespace block
namespace COMMON
{

InputGameShortName::InputGameShortName()
{
	this->_ConstructorID = 182989251;
}

InputGameShortName::InputGameShortName(COMMON::InputUser* bot_id, FString short_name)
{
	this->_ConstructorID = 182989251;
	this->bot_id = bot_id;
	this->short_name = short_name;
}
void InputGameShortName::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->bot_id->OnSend(Writer);
	Writer.TGWriteString(this->short_name);
}


void InputGameShortName::OnResponce(BinaryReader& Reader)
{
	bot_id = reinterpret_cast<COMMON::InputUser*>(Reader.TGReadObject());
	short_name = Reader.TGReadString();
}
InputGameShortName::~InputGameShortName()
{

}
}//end namespace block
