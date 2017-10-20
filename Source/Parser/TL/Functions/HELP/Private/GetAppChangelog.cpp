#include "../Public/GetAppChangelog.h"


//begin namespace block
namespace HELP
{

GetAppChangelog::GetAppChangelog()
{
	this->_ConstructorID = -1877938321;
	this->_ContentRelated = true;
}

GetAppChangelog::GetAppChangelog(FString prev_app_version)
{
	this->_ConstructorID = -1877938321;
	this->_ContentRelated = true;
	this->prev_app_version = prev_app_version;
}
void GetAppChangelog::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->prev_app_version);
}


void GetAppChangelog::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAppChangelog::~GetAppChangelog()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
