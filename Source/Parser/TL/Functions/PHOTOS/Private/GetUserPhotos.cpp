#include "../Public/GetUserPhotos.h"


//begin namespace block
namespace PHOTOS
{

GetUserPhotos::GetUserPhotos()
{
	this->_ConstructorID = -1848823128;
	this->_ContentRelated = true;
}

GetUserPhotos::GetUserPhotos(COMMON::InputUser*  user_id, int32 offset, unsigned long long max_id, int32 limit)
{
	this->_ConstructorID = -1848823128;
	this->_ContentRelated = true;
	this->user_id = user_id;
	this->offset = offset;
	this->max_id = max_id;
	this->limit = limit;
}
void GetUserPhotos::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(this->offset);
	Writer.WriteLong(this->max_id);
	Writer.WriteInt(this->limit);
}


void GetUserPhotos::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PHOTOS::Photos*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetUserPhotos::~GetUserPhotos()
{
	if(this->user_id)
	{
		delete this->user_id;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
