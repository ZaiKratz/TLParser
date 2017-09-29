#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Updates/Public/Difference.h"

//begin namespace block
namespace UPDATES
{
class GetDifference : public TLBaseObject
{
public:
	GetDifference();
	GetDifference(int32 pts, int32 pts_total_limit, FDateTime date, int32 qts);

	~GetDifference();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsTotalLimit() const
	{
		 return this->pts_total_limit;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 Getqts() const
	{
		 return this->qts;
	}

	UPDATES::Difference* GetResult() const
	{
		 return this->result;
	}

private:
	int32 pts;
	 int32 pts_total_limit;
	 FDateTime date;
	 int32 qts;
	UPDATES::Difference* result;
};
} //end namespace block
