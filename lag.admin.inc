<?php
/**
 * Module administration.
 */
function lag_admin_settings() {

  $roles = user_roles(FALSE);

  $settings = variable_get('lag', array());
  if (empty($settings)) {
    $settings = array_pad($settings, count($roles)+1, 0);
  }

  $form = array();
  $form['#tree'] = TRUE;

  $options = array(
    0        => 'No lag',
    500000   => 'Half a second',
    1000000  => '1 second',
    2000000  => '2 seconds',
    4000000  => '4 seconds',
    8000000  => '8 seconds',
    16000000 => '16 seconds',
    32000000 => '32 seconds',
  );

  foreach ($roles as $rid => $role) {
    $form['lag'][$rid] = array(
      '#title' => $role,
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $settings[$rid],
      '#description' => t('The amount of lag that users with the !role role should receive on each page load.', array('!role' => $role)),
    );
  }

  return system_settings_form($form);
}
