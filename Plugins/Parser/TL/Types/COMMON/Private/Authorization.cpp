#include "../Public/Authorization.h"


//begin namespace block
namespace COMMON
{

Authorization::Authorization()
{
	this->_ConstructorID = -152636805;
}

Authorization::Authorization(unsigned long long hash, int32 flags, FString device_model, FString platform, FString system_version, int32 api_id, FString app_name, FString app_version, int32 date_created, int32 date_active, FString ip, FString country, FString region)
{
	this->_ConstructorID = -152636805;
	this->hash = hash;
	this->flags = flags;
	this->device_model = device_model;
	this->platform = platform;
	this->system_version = system_version;
	this->api_id = api_id;
	this->app_name = app_name;
	this->app_version = app_version;
	this->date_created = date_created;
	this->date_active = date_active;
	this->ip = ip;
	this->country = country;
	this->region = region;
}
void Authorization::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->hash);
	Writer.WriteInt(this->flags);
	Writer.TGWriteString(this->device_model);
	Writer.TGWriteString(this->platform);
	Writer.TGWriteString(this->system_version);
	Writer.WriteInt(this->api_id);
	Writer.TGWriteString(this->app_name);
	Writer.TGWriteString(this->app_version);
	Writer.WriteInt(this->date_created);
	Writer.WriteInt(this->date_active);
	Writer.TGWriteString(this->ip);
	Writer.TGWriteString(this->country);
	Writer.TGWriteString(this->region);
}


void Authorization::OnResponce(BinaryReader& Reader)
{
	hash = Reader.ReadLong();
	flags = Reader.ReadInt();
	device_model = Reader.TGReadString();
	platform = Reader.TGReadString();
	system_version = Reader.TGReadString();
	api_id = Reader.ReadInt();
	app_name = Reader.TGReadString();
	app_version = Reader.TGReadString();
	date_created = Reader.ReadInt();
	date_active = Reader.ReadInt();
	ip = Reader.TGReadString();
	country = Reader.TGReadString();
	region = Reader.TGReadString();
}
Authorization::~Authorization()
{

}
}//end namespace block
