###########################################################
#
# FM App platform build setup
#
# This file is evaluated as part of the "prepare" stage
# and can be used to set up prerequisites for the build,
# such as generating header files
#
###########################################################

# The list of header files that control the HS configuration
set(FM_PLATFORM_CONFIG_FILE_LIST
  fm_internal_cfg.h
  fm_msgids.h
  fm_platform_cfg.h
)

# Create wrappers around the all the config header files
# This makes them individually overridable by the missions, without modifying
# the distribution default copies
foreach(FM_CFGFILE ${FM_PLATFORM_CONFIG_FILE_LIST})
  get_filename_component(CFGKEY "${FM_CFGFILE}" NAME_WE)
  if (DEFINED FM_CFGFILE_SRC_${CFGKEY})
    set(DEFAULT_SOURCE "${FM_CFGFILE_SRC_${CFGKEY}}")
  else()
    set(DEFAULT_SOURCE "${CMAKE_CURRENT_LIST_DIR}/config/default_${FM_CFGFILE}")
  endif()
  generate_config_includefile(
    FILE_NAME           "${FM_CFGFILE}"
    FALLBACK_FILE       ${DEFAULT_SOURCE}
  )
endforeach()
