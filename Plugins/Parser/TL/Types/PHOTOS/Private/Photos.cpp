#include "../Public/Photos.h"


//begin namespace block
namespace PHOTOS
{

Photos::Photos()
{
	this->_ConstructorID = -1519727987;
}

Photos::Photos(TArray<COMMON::Photo*> photos, TArray<COMMON::User*> users)
{
	this->_ConstructorID = -1519727987;
	this->photos = photos;
	this->users = users;
}
void Photos::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->photos.Num());
	for(auto X : this->photos)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void Photos::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len2912 = Reader.ReadInt();
	for(int32 i = 0; i < Len2912; i++)
	{
	auto X = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	photos.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len1333 = Reader.ReadInt();
	for(int32 i = 0; i < Len1333; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
Photos::~Photos()
{

}
}//end namespace block
