#include "../Public/InputMediaDocument.h"


//begin namespace block
namespace COMMON
{

InputMediaDocument::InputMediaDocument()
{
	this->_ConstructorID = 1523279502;
}

InputMediaDocument::InputMediaDocument(COMMON::InputDocument*  id, FString caption, int32 ttl_seconds)
{
	this->_ConstructorID = 1523279502;
	this->id = id;
	this->caption = caption;
	this->ttl_seconds = ttl_seconds;
}
void InputMediaDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(ttl_seconds)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->id->OnSend(Writer);
	Writer.TGWriteString(this->caption);
	if(this->ttl_seconds)
	{
	Writer.WriteInt(this->ttl_seconds);
	}
}


void InputMediaDocument::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = reinterpret_cast<COMMON::InputDocument* >(Reader.TGReadObject());
	caption = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	ttl_seconds = Reader.ReadInt();
	}
	this->_Responded = true;
}
InputMediaDocument::~InputMediaDocument()
{
	if(this->id)
	{
		delete this->id;
	}
}
}//end namespace block
