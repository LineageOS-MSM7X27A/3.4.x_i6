
#ifndef __MSM_BATTERY_H__
#define __MSM_BATTERY_H__

#define AC_CHG	0x00000001
#define USB_CHG	0x00000002
#define UNKNOWN_CHG	0x00000004

struct msm_psy_batt_pdata {
	u32 voltage_max_design;
	u32 voltage_min_design;
	u32 voltage_fail_safe;
	u32 batt_technology;
	u32 avail_chg_sources;
	u32 (*calculate_capacity)(u32 voltage);
};

struct msm_batt_gauge {
	int (*get_battery_mvolts) (void);
	int (*get_battery_temperature) (void);
	int (*is_battery_present) (void);
	int (*is_battery_temp_within_range) (void);
	int (*is_battery_id_valid) (void);
	int (*get_battery_status)(void);
	int (*get_batt_remaining_capacity) (void);
};


#ifdef CONFIG_MSM_SM_EVENT
uint32_t msm_batt_get_batt_voltage (void);
#endif
int msm_batt_fuel_register(struct msm_batt_gauge* batt);
void msm_batt_fuel_unregister(struct msm_batt_gauge* batt);

#endif

