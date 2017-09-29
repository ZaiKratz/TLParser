#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/ExportedAuthorization.h"

//begin namespace block
namespace AUTH
{
class ExportAuthorization : public TLBaseObject
{
public:
	ExportAuthorization();
	ExportAuthorization(int32 dc_id);

	~ExportAuthorization();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

	AUTH::ExportedAuthorization* GetResult() const
	{
		 return this->result;
	}

private:
	int32 dc_id;
	AUTH::ExportedAuthorization* result;
};
} //end namespace block
