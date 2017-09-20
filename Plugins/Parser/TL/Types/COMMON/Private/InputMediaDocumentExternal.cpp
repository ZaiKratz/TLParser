#include "../Public/InputMediaDocumentExternal.h"


//begin namespace block
namespace COMMON
{

InputMediaDocumentExternal::InputMediaDocumentExternal()
{
	this->_ConstructorID = 893646774;
}

InputMediaDocumentExternal::InputMediaDocumentExternal(FString url, FString caption, int32 ttl_seconds)
{
	this->_ConstructorID = 893646774;
	this->url = url;
	this->caption = caption;
	this->ttl_seconds = ttl_seconds;
}
void InputMediaDocumentExternal::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!ttl_seconds)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->caption);
	if(!this->ttl_seconds)
	{
	Writer.WriteInt(this->ttl_seconds);
	}
}


void InputMediaDocumentExternal::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	url = Reader.TGReadString();
	caption = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	ttl_seconds = Reader.ReadInt();
	}
}
InputMediaDocumentExternal::~InputMediaDocumentExternal()
{

}
}//end namespace block
