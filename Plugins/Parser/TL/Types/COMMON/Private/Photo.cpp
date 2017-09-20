#include "../Public/Photo.h"


//begin namespace block
namespace COMMON
{

Photo::Photo()
{
	this->_ConstructorID = 702384274;
}

Photo::Photo(bool has_stickers, unsigned long long id, unsigned long long access_hash, FDateTime date, TArray<COMMON::PhotoSize*> sizes)
{
	this->_ConstructorID = 702384274;
	this->has_stickers = has_stickers;
	this->id = id;
	this->access_hash = access_hash;
	this->date = date;
	this->sizes = sizes;
}
void Photo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!has_stickers)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->id);
	Writer.WriteLong(this->access_hash);
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->sizes.Num());
	for(auto X : this->sizes)
	{
	X->OnSend(Writer);
	}
}


void Photo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		has_stickers = true;
	}
	id = Reader.ReadLong();
	access_hash = Reader.ReadLong();
	date = Reader.TGReadDate();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7357 = Reader.ReadInt();
	for(int32 i = 0; i < Len7357; i++)
	{
	auto X = reinterpret_cast<COMMON::PhotoSize*>(Reader.TGReadObject());
	sizes.Add(X);
	}
}
Photo::~Photo()
{

}
}//end namespace block
