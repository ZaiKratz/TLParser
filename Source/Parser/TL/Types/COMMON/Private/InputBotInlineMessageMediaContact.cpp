#include "../Public/InputBotInlineMessageMediaContact.h"


//begin namespace block
namespace COMMON
{

InputBotInlineMessageMediaContact::InputBotInlineMessageMediaContact()
{
	this->_ConstructorID = 766443943;
}

InputBotInlineMessageMediaContact::InputBotInlineMessageMediaContact(FString phone_number, FString first_name, FString last_name, TLBaseObject*  reply_markup)
{
	this->_ConstructorID = 766443943;
	this->phone_number = phone_number;
	this->first_name = first_name;
	this->last_name = last_name;
	this->reply_markup = reply_markup;
}
void InputBotInlineMessageMediaContact::OnSend(BinaryWriter& Writer)
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

	Writer.TGWriteString(this->phone_number);
	Writer.TGWriteString(this->first_name);
	Writer.TGWriteString(this->last_name);
	if(this->reply_markup)
	{
	this->reply_markup->OnSend(Writer);
	}
}


void InputBotInlineMessageMediaContact::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	phone_number = Reader.TGReadString();
	first_name = Reader.TGReadString();
	last_name = Reader.TGReadString();
	if((Flags & (1 << 2)) != 0) 
	{
	reply_markup = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
InputBotInlineMessageMediaContact::~InputBotInlineMessageMediaContact()
{
	if(this->reply_markup)
	{
		delete this->reply_markup;
	}
}
}//end namespace block
