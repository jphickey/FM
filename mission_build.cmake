###########################################################
#
# FM App mission build setup
#
# This file is evaluated as part of the "prepare" stage
# and can be used to set up prerequisites for the build,
# such as generating header files
#
###########################################################

# Add stand alone documentation
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/docs/dox_src ${MISSION_BINARY_DIR}/docs/fm-usersguide)

# The list of header files that control the HS configuration
set(FM_MISSION_CONFIG_FILE_LIST
  fm_interface_cfg.h
  fm_fcncodes.h
  fm_mission_cfg.h
  fm_msgdefs.h
  fm_msg.h
  fm_tbldefs.h
  fm_tbl.h
)

if (CFE_EDS_ENABLED_BUILD)

  # In an EDS-based build, these files come generated from the EDS tool
  set(FM_CFGFILE_SRC_fm_mission_cfg "fm_eds_designparameters.h")
  set(FM_CFGFILE_SRC_fm_fcncodes    "fm_eds_cc.h")
  set(FM_CFGFILE_SRC_fm_msg         "fm_eds_typedefs.h")
  set(FM_CFGFILE_SRC_fm_tbl         "fm_eds_typedefs.h")

else(CFE_EDS_ENABLED_BUILD)

  # In a non-EDS build, the user supplies these files, plus a couple more
  # There are defaults for all in the "config" dir
  list (APPEND FM_MISSION_CONFIG_FILE_LIST
    fm_msgstruct.h
    fm_tblstruct.h
  )

endif(CFE_EDS_ENABLED_BUILD)

# Create wrappers around the all the config header files
# This makes them individually overridable by the missions, without modifying
# the distribution default copies
foreach(FM_CFGFILE ${FM_MISSION_CONFIG_FILE_LIST})
  get_filename_component(CFGKEY "${FM_CFGFILE}" NAME_WE)
  if (DEFINED FM_CFGFILE_SRC_${CFGKEY})
    set(DEFAULT_SOURCE GENERATED_FILE "${FM_CFGFILE_SRC_${CFGKEY}}")
  else()
    set(DEFAULT_SOURCE FALLBACK_FILE "${CMAKE_CURRENT_LIST_DIR}/config/default_${FM_CFGFILE}")
  endif()
  generate_config_includefile(
    FILE_NAME           "${FM_CFGFILE}"
    ${DEFAULT_SOURCE}
  )
endforeach()
