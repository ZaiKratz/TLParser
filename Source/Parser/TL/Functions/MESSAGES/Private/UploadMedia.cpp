#include "../Public/UploadMedia.h"


//begin namespace block
namespace MESSAGES
{

UploadMedia::UploadMedia()
{
	this->_ConstructorID = 1369162417;
	this->_ContentRelated = true;
}

UploadMedia::UploadMedia(PRIVATE::InputPeer*  peer, PRIVATE::InputMedia*  media)
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
	this->result = reinterpret_cast<PRIVATE::MessageMedia*>(Reader.TGReadObject());
	this->_Responded = true;
}
UploadMedia::~UploadMedia()
{

}
}//end namespace block
