#include "../Public/InitConnection.h"


//begin namespace block
namespace COMMON
{

InitConnection::InitConnection()
{
	this->_ConstructorID = -1508030265;
	this->_ContentRelated = true;
}

InitConnection::InitConnection(int32 api_id, FString device_model, FString system_version, FString app_version, FString system_lang_code, FString lang_pack, FString lang_code, ::TLBaseObject* query)
{
	this->_ConstructorID = -1508030265;
	this->_ContentRelated = true;
	this->api_id = api_id;
	this->device_model = device_model;
	this->system_version = system_version;
	this->app_version = app_version;
	this->system_lang_code = system_lang_code;
	this->lang_pack = lang_pack;
	this->lang_code = lang_code;
	this->query = query;
}
void InitConnection::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->api_id);
	Writer.TGWriteString(this->device_model);
	Writer.TGWriteString(this->system_version);
	Writer.TGWriteString(this->app_version);
	Writer.TGWriteString(this->system_lang_code);
	Writer.TGWriteString(this->lang_pack);
	Writer.TGWriteString(this->lang_code);
	this->query->OnSend(Writer);
}


void InitConnection::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
}
InitConnection::~InitConnection()
{

}
}//end namespace block
