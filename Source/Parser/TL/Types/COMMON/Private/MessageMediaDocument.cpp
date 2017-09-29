#include "../Public/MessageMediaDocument.h"


//begin namespace block
namespace COMMON
{

MessageMediaDocument::MessageMediaDocument()
{
	this->_ConstructorID = 2084836563;
}

MessageMediaDocument::MessageMediaDocument(COMMON::Document*  document, FString caption, int32 ttl_seconds)
{
	this->_ConstructorID = 2084836563;
	this->document = document;
	this->caption = caption;
	this->ttl_seconds = ttl_seconds;
}
void MessageMediaDocument::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(document)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!caption.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(ttl_seconds)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(!this->document)
	{
	this->document->OnSend(Writer);
	}
	Writer.TGWriteString(this->caption);
	if(!this->ttl_seconds)
	{
	Writer.WriteInt(this->ttl_seconds);
	}
}


void MessageMediaDocument::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	document = reinterpret_cast<COMMON::Document* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	caption = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	ttl_seconds = Reader.ReadInt();
	}
	this->_Responded = true;
}
MessageMediaDocument::~MessageMediaDocument()
{

}
}//end namespace block
