#include "../Public/InputBotInlineResultGame.h"


//begin namespace block
namespace COMMON
{

InputBotInlineResultGame::InputBotInlineResultGame()
{
	this->_ConstructorID = 1336154098;
}

InputBotInlineResultGame::InputBotInlineResultGame(FString id, FString short_name, TLBaseObject*  send_message)
{
	this->_ConstructorID = 1336154098;
	this->id = id;
	this->short_name = short_name;
	this->send_message = send_message;
}
void InputBotInlineResultGame::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->id);
	Writer.TGWriteString(this->short_name);
	this->send_message->OnSend(Writer);
}


void InputBotInlineResultGame::OnResponce(BinaryReader& Reader)
{
	id = Reader.TGReadString();
	short_name = Reader.TGReadString();
	send_message = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
InputBotInlineResultGame::~InputBotInlineResultGame()
{
	if(this->send_message)
	{
		delete this->send_message;
	}
}
}//end namespace block
