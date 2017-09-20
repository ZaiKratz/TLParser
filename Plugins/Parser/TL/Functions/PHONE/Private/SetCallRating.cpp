#include "../Public/SetCallRating.h"


//begin namespace block
namespace PHONE
{

SetCallRating::SetCallRating()
{
	this->_ConstructorID = 879383324;
	this->_ContentRelated = true;
}

SetCallRating::SetCallRating(COMMON::InputPhoneCall* peer, int32 rating, FString comment)
{
	this->_ConstructorID = 879383324;
	this->_ContentRelated = true;
	this->peer = peer;
	this->rating = rating;
	this->comment = comment;
}
void SetCallRating::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->rating);
	Writer.TGWriteString(this->comment);
}


void SetCallRating::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
SetCallRating::~SetCallRating()
{

}
}//end namespace block
