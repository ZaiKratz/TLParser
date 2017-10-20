#include "../Public/Photo.h"


//begin namespace block
namespace PHOTOS
{

Photo::Photo()
{
	this->_ConstructorID = 539045032;
}

Photo::Photo(COMMON::Photo*  photo, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 539045032;
	this->photo = photo;
	this->users = users;
}
void Photo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->photo->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void Photo::OnResponce(BinaryReader& Reader)
{
	photo = reinterpret_cast<COMMON::Photo* >(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len24508 = Reader.ReadInt();
	for(int32 i = 0; i < Len24508; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
Photo::~Photo()
{
	if(this->photo)
	{
		delete this->photo;
	}
}
}//end namespace block
