#include "../Public/WallPaper.h"


//begin namespace block
namespace COMMON
{

WallPaper::WallPaper()
{
	this->_ConstructorID = 1463201996;
}

WallPaper::WallPaper(int32 id, FString title, TArray<COMMON::PhotoSize*> sizes, int32 color)
{
	this->_ConstructorID = 1463201996;
	this->id = id;
	this->title = title;
	this->sizes = sizes;
	this->color = color;
}
void WallPaper::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.TGWriteString(this->title);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->sizes.Num());
	for(auto X : this->sizes)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(this->color);
}


void WallPaper::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	title = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len18223 = Reader.ReadInt();
	for(int32 i = 0; i < Len18223; i++)
	{
	auto X = reinterpret_cast<COMMON::PhotoSize*>(Reader.TGReadObject());
	sizes.Add(X);
	}
	color = Reader.ReadInt();
}
WallPaper::~WallPaper()
{

}
}//end namespace block
