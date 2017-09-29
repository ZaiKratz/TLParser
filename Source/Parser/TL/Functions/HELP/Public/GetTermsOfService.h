#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Help/Public/TermsOfService.h"

//begin namespace block
namespace HELP
{
class GetTermsOfService : public TLBaseObject
{
public:
	GetTermsOfService();
	~GetTermsOfService();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	HELP::TermsOfService* GetResult() const
	{
		 return this->result;
	}

private:
	HELP::TermsOfService* result;
};
} //end namespace block
