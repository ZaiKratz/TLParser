#include "../Public/PhotosSlice.h"


//begin namespace block
namespace PHOTOS
{

PhotosSlice::PhotosSlice()
{
	this->_ConstructorID = 352657236;
}

PhotosSlice::PhotosSlice(int32 count, TArray<COMMON::Photo*>  photos, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 352657236;
	this->count = count;
	this->photos = photos;
	this->users = users;
}
void PhotosSlice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->count);
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


void PhotosSlice::OnResponce(BinaryReader& Reader)
{
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len19823 = Reader.ReadInt();
	for(int32 i = 0; i < Len19823; i++)
	{
	auto X = reinterpret_cast<COMMON::Photo*>(Reader.TGReadObject());
	photos.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26681 = Reader.ReadInt();
	for(int32 i = 0; i < Len26681; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
PhotosSlice::~PhotosSlice()
{

}
}//end namespace block
