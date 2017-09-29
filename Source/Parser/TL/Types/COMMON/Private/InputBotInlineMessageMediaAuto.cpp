#include "../Public/InputBotInlineMessageMediaAuto.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageMediaAuto::InputBotInlineMessageMediaAuto()
{
	this->_ConstructorID = 691006739;
}

InputBotInlineMessageMediaAuto::InputBotInlineMessageMediaAuto(FString caption, PRIVATE::ReplyMarkup*  reply_markup)
{
	this->_ConstructorID = 691006739;
	this->caption = caption;
	this->reply_markup = reply_markup;
}
void InputBotInlineMessageMediaAuto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(reply_markup)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->caption);
	if(!this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void InputBotInlineMessageMediaAuto::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	caption = Reader.TGReadString();
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<PRIVATE::ReplyMarkup* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
InputBotInlineMessageMediaAuto::~InputBotInlineMessageMediaAuto()
{

}
}//end namespace block
