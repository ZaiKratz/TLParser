#include "../Public/FoundGifCached.h"


//begin namespace block
namespace COMMON
{

FoundGifCached::FoundGifCached()
{
	this->_ConstructorID = -1670052855;
}

FoundGifCached::FoundGifCached(FString url, COMMON::Photo*  photo, COMMON::Document*  document)
{
	this->_ConstructorID = -1670052855;
	this->url = url;
	this->photo = photo;
	this->document = document;
}
void FoundGifCached::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	this->photo->OnSend(Writer);
	this->document->OnSend(Writer);
}


void FoundGifCached::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
	photo = reinterpret_cast<COMMON::Photo* >(Reader.TGReadObject());
	document = reinterpret_cast<COMMON::Document* >(Reader.TGReadObject());
	this->_Responded = true;
}
FoundGifCached::~FoundGifCached()
{
	if(this->photo)
	{
		delete this->photo;
	}
	if(this->document)
	{
		delete this->document;
	}
}
}//end namespace block
