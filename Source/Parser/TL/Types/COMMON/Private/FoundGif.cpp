#include "../Public/FoundGif.h"


//begin namespace block
namespace COMMON
{

FoundGif::FoundGif()
{
	this->_ConstructorID = 372165663;
}

FoundGif::FoundGif(FString url, FString thumb_url, FString content_url, FString content_type, int32 w, int32 h)
{
	this->_ConstructorID = 372165663;
	this->url = url;
	this->thumb_url = thumb_url;
	this->content_url = content_url;
	this->content_type = content_type;
	this->w = w;
	this->h = h;
}
void FoundGif::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->url);
	Writer.TGWriteString(this->thumb_url);
	Writer.TGWriteString(this->content_url);
	Writer.TGWriteString(this->content_type);
	Writer.WriteInt(this->w);
	Writer.WriteInt(this->h);
}


void FoundGif::OnResponce(BinaryReader& Reader)
{
	url = Reader.TGReadString();
	thumb_url = Reader.TGReadString();
	content_url = Reader.TGReadString();
	content_type = Reader.TGReadString();
	w = Reader.ReadInt();
	h = Reader.ReadInt();
	this->_Responded = true;
}
FoundGif::~FoundGif()
{

}
}//end namespace block
