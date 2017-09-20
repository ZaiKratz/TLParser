#include "../Public/InputBotInlineMessageGame.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageGame::InputBotInlineMessageGame()
{
	this->_ConstructorID = 1683505739;
}

InputBotInlineMessageGame::InputBotInlineMessageGame(PRIVATE::ReplyMarkup* reply_markup)
{
	this->_ConstructorID = 1683505739;
	this->reply_markup = reply_markup;
}
void InputBotInlineMessageGame::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(!this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void InputBotInlineMessageGame::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<PRIVATE::ReplyMarkup*>(Reader.TGReadObject());
	}
}
InputBotInlineMessageGame::~InputBotInlineMessageGame()
{

}
}//end namespace block
