#include "../Public/DeletePhotos.h"


//begin namespace block
namespace PHOTOS
{

DeletePhotos::DeletePhotos()
{
	this->_ConstructorID = 796905351;
	this->_ContentRelated = true;
}

DeletePhotos::DeletePhotos(TArray<COMMON::InputPhoto*> id)
{
	this->_ConstructorID = 796905351;
	this->_ContentRelated = true;
	this->id = id;
}
void DeletePhotos::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	X->OnSend(Writer);
	}
}


void DeletePhotos::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();
	int32 Count = Reader.ReadLong();
	for(int32 i = 0; i < Count; i++)
	{
		this->result.Add(Reader.ReadLong());
	}
}
DeletePhotos::~DeletePhotos()
{

}
}//end namespace block
