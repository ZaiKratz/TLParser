#include "../Public/GetSavedGifs.h"


//begin namespace block
namespace MESSAGES
{

GetSavedGifs::GetSavedGifs()
{
	this->_ConstructorID = 1379778435;
	this->_ContentRelated = true;
}

GetSavedGifs::GetSavedGifs(int32 hash)
{
	this->_ConstructorID = 1379778435;
	this->_ContentRelated = true;
	this->hash = hash;
}
void GetSavedGifs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
}


void GetSavedGifs::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::SavedGifs*>(Reader.TGReadObject());
}
GetSavedGifs::~GetSavedGifs()
{

}
}//end namespace block
