#include "../Public/Photo.h"


//begin namespace block
namespace PHOTOS
{

Photo::Photo()
{
	this->_ConstructorID = -1473502944;
}

Photo::Photo(COMMON::Photo* photo, TArray<COMMON::User*> users)
{
	this->_ConstructorID = -1473502944;
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
	photo = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len23875 = Reader.ReadInt();
	for(int32 i = 0; i < Len23875; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
Photo::~Photo()
{

}
}//end namespace block
