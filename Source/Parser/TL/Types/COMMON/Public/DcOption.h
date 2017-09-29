#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DcOption : public TLBaseObject
{
public:
	DcOption();
	DcOption(bool ipv6, bool media_only, bool tcpo_only, bool cdn, bool Static, int32 id, FString ip_address, int32 port);

	~DcOption();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getipv6() const
	{
		 return this->ipv6;
	}

	bool GetMediaOnly() const
	{
		 return this->media_only;
	}

	bool GetTcpoOnly() const
	{
		 return this->tcpo_only;
	}

	bool Getcdn() const
	{
		 return this->cdn;
	}

	bool GetStatic() const
	{
		 return this->Static;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	FString GetIpAddress() const
	{
		 return this->ip_address;
	}

	int32 Getport() const
	{
		 return this->port;
	}

private:
	bool ipv6;
	 bool media_only;
	 bool tcpo_only;
	 bool cdn;
	 bool Static;
	 int32 id;
	 FString ip_address;
	 int32 port;
};
} //end namespace block
