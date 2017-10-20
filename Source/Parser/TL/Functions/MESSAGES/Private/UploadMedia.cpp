#include "../Public/UploadMedia.h"


//begin namespace block
namespace MESSAGES
{

UploadMedia::UploadMedia()
{
	this->_ConstructorID = 1369162417;
	this->_ContentRelated = true;
}

UploadMedia::UploadMedia(TLBaseObject*  peer, TLBaseObject*  media)
{
	this->_ConstructorID = 1369162417;
	this->_ContentRelated = true;
	this->peer = peer;
	this->media = media;
}
void UploadMedia::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	this->media->OnSend(Writer);
}


void UploadMedia::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	this->_Responded = true;
}
UploadMedia::~UploadMedia()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->media)
	{
		delete this->media;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
