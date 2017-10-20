#include "../Public/ResetTopPeerRating.h"


//begin namespace block
namespace CONTACTS
{

ResetTopPeerRating::ResetTopPeerRating()
{
	this->_ConstructorID = 451113900;
	this->_ContentRelated = true;
}

ResetTopPeerRating::ResetTopPeerRating(TLBaseObject*  category, TLBaseObject*  peer)
{
	this->_ConstructorID = 451113900;
	this->_ContentRelated = true;
	this->category = category;
	this->peer = peer;
}
void ResetTopPeerRating::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->category->OnSend(Writer);
	this->peer->OnSend(Writer);
}


void ResetTopPeerRating::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ResetTopPeerRating::~ResetTopPeerRating()
{
	if(this->category)
	{
		delete this->category;
	}
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block
