#include "../Public/ChatPhoto.h"


//begin namespace block
namespace COMMON
{

ChatPhoto::ChatPhoto()
{
	this->_ConstructorID = 1632839530;
}

ChatPhoto::ChatPhoto(COMMON::FileLocation*  photo_small, COMMON::FileLocation*  photo_big)
{
	this->_ConstructorID = 1632839530;
	this->photo_small = photo_small;
	this->photo_big = photo_big;
}
void ChatPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->photo_small->OnSend(Writer);
	this->photo_big->OnSend(Writer);
}


void ChatPhoto::OnResponce(BinaryReader& Reader)
{
	photo_small = reinterpret_cast<COMMON::FileLocation* >(Reader.TGReadObject());
	photo_big = reinterpret_cast<COMMON::FileLocation* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChatPhoto::~ChatPhoto()
{
	if(this->photo_small)
	{
		delete this->photo_small;
	}
	if(this->photo_big)
	{
		delete this->photo_big;
	}
}
}//end namespace block
